program casa_moderna;
var
  fin, fout : text;
  N, i, j, k, x, tmp, sum_all, pmin, res_sum : integer;
  time : array of integer;
  price : array of integer;
  subset : array of integer;
  subset_copy : array of integer;
  res_plan : array of integer;
  
  function order_plan(sub : array of integer) : boolean;
  var
    N, i, j, p, zero : integer;
  begin
    for i := 1 to length(sub) - 1 do //сортировка массива
    begin
      for j := 0 to i do begin
        if (sub[i] < sub[j]) then
        begin
          p := sub[i];
          sub[i] := sub[j];
          sub[j] := p;
        end;
      end;
    end;
  
    i := 0;
    for j := 0 to length(sub) - 1 do
    begin
      if (sub[j] = 0) then
      begin
        zero := zero + 1;
      end;
      if (sub[j] <> 0) and (i + 1 <= sub[j]) then
      begin
        i := i + 1;
      end;
    end;
    i := i + zero;

    if (i = length(sub)) then
    begin
      order_plan := true;
    end
    else
    begin
      order_plan := false;
    end;
  end;
  
  function profit(subset : array of integer) : integer;
  var
    i, p, sum : integer;
  begin
    for i := 0 to length(subset) - 1 do //подсчёт суммы подмножества
    begin
      if (subset[i] <> 0) then
      begin
        p := price[i];
        sum := sum + p;
      end;
    end;
    profit := sum;
  end;
  
begin
  assign(fin, 'cas.in');
  reset(fin);
  assign(fout, 'cas.out');
  rewrite(fout);
  read(fin, N);
  setLength(time, N);
  setLength(price, N);
  setLength(subset, N);
  setLength(subset_copy, N);
  setLength(res_plan, N);
  for i := 0 to N - 1 do //считывание данных в массив
  begin
    read(fin, time[i]);
    read(fin, price[i]);
  end;
  
  for i := 0 to length(price) - 1 do //общая сумма
  begin
    sum_all := sum_all + price[i];
  end;
  
  i := 0;
  tmp := 1;
  while i < N do //math.pow(2, time.length);
  begin
    tmp := tmp * 2;
    i := i + 1;
  end;
  
  for x := 0 to tmp - 1 do //создание подмножеств
  begin
    k := x;
    i := 0;
    while (k > 0) do
    begin
      if (k mod 2 = 1) then
      begin
        subset[i] := time[i];
        //writeln('sub[i] = ', subset[i], ' i = ', i, ' time[i] = ', time[i]);
      end;
      k := k div 2;
      i := i + 1;
    end;
    
    for i := 0 to length(subset) - 1 do
    begin
      subset_copy[i] := subset[i];
    end;
    
    if (order_plan(subset_copy) = true) then //подсчёт прибыли и потерь
    begin
      if (profit(subset) > res_sum) then
      begin
        for i := 0 to length(subset) - 1 do
        begin
          for j := 0 to length(subset_copy) - 1 do
          begin
            if (subset[i] = subset_copy[j]) and (subset_copy[j] <> 0) then
            begin
              res_plan[j] := i + 1;
              subset_copy[j] := 0;
              break;
            end;  
          end;
        end;
        res_sum := profit(subset);
        pmin := sum_all - profit(subset);
      end;
    end;
    for i := 0 to length(subset) - 1 do
    begin
      subset[i] := 0;
    end;
  end;
  write('sum = ', res_sum);
  writeln(' pmin = ', pmin);
  for i := 0 to length(res_plan) - 1 do
  begin
    if (res_plan[i] <> 0) then
    begin
      writeln(res_plan[i]);  
    end;
  end;
  
  close(fin);
  close(fout);
end.
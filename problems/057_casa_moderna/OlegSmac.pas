program casa_moderna;
var
  fin, fout : text;
  N, i, j, k, x, tmp, sum_all, pmin, res_sum, p, prof : integer;
  time : array of integer;
  price : array of integer;
  subset : array of integer;
  index : array of integer;
  res_plan : array of integer;
  
  function order_plan(sub : array of integer) : boolean;
  var
    N, i, j, zero : integer;
  begin
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
  setLength(index, N);
  setLength(res_plan, N);
  for i := 0 to N - 1 do //считывание данных в массив
  begin
    read(fin, time[i]);
    read(fin, price[i]);
  end;
  
  for i := 0 to length(time) - 1 do
  begin
    index[i] := i;
  end;
  
  for i := 0 to length(time) - 1 do //сортировка time и price
  begin
    for j := 0 to i do begin
      if (time[i] < time[j]) then
      begin
        p := time[i];
        time[i] := time[j];
        time[j] := p;
        p := price[i];
        price[i] := price[j];
        price[j] := p;
        p := index[i];
        index[i] := index[j];
        index[j] := p;
      end;
    end;
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
    
    if (order_plan(subset) = true) then //проверка выполнения всех задач
    begin
      prof := profit(subset);
      if (prof > res_sum) then //подсчёт прибыли и потерь
      begin
        res_sum := prof;
        pmin := sum_all - prof;
        
        for i := 0 to length(subset) - 1 do
        begin
          res_plan[i] := 0;
          if (subset[i] <> 0) then
          begin
            res_plan[i] := index[i] + 1;
          end;
        end;
      end;
    end;
    for i := 0 to length(subset) - 1 do
    begin
      subset[i] := 0;
    end;
  end;
  write(res_sum);
  writeln(' ',pmin);
  write(fout, res_sum);
  writeln(fout, ' ', pmin);
  for i := 0 to length(res_plan) - 1 do
  begin
    if (res_plan[i] <> 0) then
    begin
      writeln(res_plan[i]);
      writeln(fout, res_plan[i]);  
    end;
  end;
  
  close(fin);
  close(fout);
end.
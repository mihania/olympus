program casa_moderna;
type
  order = record
     time : integer;
     price : integer;
     index : integer;
  end;
var
  orders : array of order;
  fin, fout : text;
  N, i, j, k, x, tmp, sum_all, pmin, res_sum, p, prof : integer;
  subset : array of integer;
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
        p := orders[i].price;
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
  setLength(orders, N);
  setLength(subset, N);
  setLength(res_plan, N);
  for i := 0 to N - 1 do //считывание данных в массив
  begin
    read(fin, orders[i].time);
    read(fin, orders[i].price);
  end;
  
  for i := 0 to length(orders) - 1 do
  begin
    orders[i].index := i;
  end;
 
  for i := 0 to length(orders) - 1 do //сортировка time и price
  begin
    for j := 0 to i do begin
      if (orders[i].time < orders[j].time) then
      begin
        p := orders[i].time;
        orders[i].time := orders[j].time;
        orders[j].time := p;
        p := orders[i].price;
        orders[i].price := orders[j].price;
        orders[j].price := p;
        p := orders[i].index;
        orders[i].index := orders[j].index;
        orders[j].index := p;
      end;
    end;
  end;
  
  for i := 0 to length(orders) - 1 do //общая сумма
  begin
    sum_all := sum_all + orders[i].price;
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
        subset[i] := orders[i].time;
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
            res_plan[i] := orders[i].index + 1;
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
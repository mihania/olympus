function area(sub : array of integer) : integer;
var i, sum : integer;
begin
  for i := 0 to length(sub) - 1 do
  begin
    if (sub[i] <> 0) and (sub[i] > sum) then
    begin
      sum := sum + sub[i];
    end;
  end;
  area := sum;
end;

var fin, fout : text;
    N, S, x, k, i, j, tmp, plosh, differ, cities, res_cit : integer;
    A : array of integer;
    subset : array of integer;
    res_sub : array of integer;
begin
  assign(fin, 'REGE.IN');
  reset(fin);
  assign(fout, 'REGE.OUT');
  rewrite(fout);
  read(fin, N);
  readln(fin, S);
  SetLength(A, N);
  SetLength(subset, N);
  SetLength(res_sub, N);
  differ := S;
  for i := 0 to N - 1 do
  begin
    readln(fin, A[i]);
  end;
  
  for i := 1 to N - 1 do //сортировака массива по возрастанию
  begin
    for j := 0 to i - 1 do
    begin
      if A[i] < A[j] then
      begin
        tmp := A[i];
        A[i] := A[j];
        A[j] := tmp;
      end;
    end;
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
        subset[i] := A[i];
      end;
      k := k div 2;
      i := i + 1;
    end;
    
    cities := 0;
    for j := 0 to length(subset) - 1 do
    begin
      if (subset[j] > 0) then
      begin
        cities := cities + 1;
      end;
    end;
    
    plosh := area(subset);
    if (plosh <= S) and (S - plosh < differ) then
    begin
      differ := S - plosh;
      res_cit := cities;
      for j := 0 to length(res_sub) - 1 do
      begin
        res_sub[j] := subset[j];
      end;
    end;
    for j := 0 to length(subset) - 1 do
    begin
      subset[j] := 0;
    end;
  end;
  
  write(fout, res_cit, ' '); //вывод ответа
  writeln(fout, differ);
  for i := 0 to length(res_sub) - 1 do
  begin
    if (res_sub[i] > 0) then
    begin
      writeln(fout, res_sub[i]);
    end;
  end;
  close(fin);
  close(fout);
end.
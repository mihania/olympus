function Solve(n, k : integer) : integer;
var a : array [1..444, 1..444, 0..1] of integer;
    i, j, x, sum1, sum0, res_sum : integer;
begin
  if (k = 1) and (n = 1) then
  begin
    res_sum := 1;
  end;
  
  for i := 1 to n do //длина 1
  begin
    a[1][i][1] := 1;
    if (i <> 1) then a[1][i][0] := 1;
  end;
  
  for i := 2 to n do
  begin
    for j := 1 to n do
    begin
      for x := 1 to j - 2 do
      begin
        sum1 := sum1 + a[i - 1][x][1];
        sum0 := sum0 + a[i - 1][x][0];
      end;
      a[i][j][1] := sum1;
      a[i][j][0] := sum0;
      sum1 := 0;
      sum0 := 0;
    end;
  end;
  
  for i := 1 to n - 1 do
  begin
    res_sum := res_sum + a[k][i][1];
  end;
  res_sum := res_sum + a[k][n][0];
  Solve := res_sum;
end;

var fin, fout : text;
    T, n, k, i : integer;
begin
  assign(fin, 'TESTS.IN');
  reset(fin);
  assign(fout, 'TESTS.OUT');
  rewrite(fout);
  readln(fin, T);
  //writeln(Solve(1, 1));
  for i := 0 to T - 1 do
  begin
    read(fin, n);
    read(fin, k);
    writeln(fout, Solve(n, k));
  end;
  close(fin);
  close(fout);  
end.
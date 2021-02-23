type BigInteger = record
     digits : array [0..259] of byte;
     size : integer;
end;

function Solve(n, k : integer) : integer;
var dp : array [1..444, 1..444, 0..1] of integer;
    i, j, x, sum1, sum0, res_sum : integer;
begin
  if (k = 1) and (n = 1) then
  begin
    res_sum := 1;
  end;
  
  for i := 1 to n do //длина 1
  begin
    dp[1][i][1] := 1;
    if (i <> 1) then dp[1][i][0] := 1;
  end;
  
  for i := 2 to k do
  begin
    for j := 1 to n do
    begin
      for x := 1 to j - 2 do
      begin
        dp[i][j][1] := dp[i][j][1] + dp[i - 1][x][1]; //сумма всех подмножеств, заканчивающихся на i элемент
        dp[i][j][0] := dp[i][j][0] + dp[i - 1][x][0]; //сумма подмножеств, в которых нет цифры 1 и которые заканчиваются на i элемент
      end;
    end;
  end;
  
  for i := 1 to n - 1 do
  begin
    res_sum := res_sum + dp[k][i][1];
  end;
  res_sum := res_sum + dp[k][n][0];
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
  for i := 0 to T - 1 do
  begin
    read(fin, n);
    read(fin, k);
    writeln(fout, Solve(n, k));
  end;
  close(fin);
  close(fout);  
end.
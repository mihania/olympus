type BigInteger = record
     digits : array [0..95] of byte;
     size : integer;
end;

var fin, fout : text;
    T, n, k, i : integer;

function Init(num : string) : BigInteger;
var res : BigInteger;
    i, err : integer;
begin
    num := trim(num); 
    for i := length(num) downto 1 do
    begin
        val(num[i], res.digits[res.size], err);
        res.size := res.size + 1;
    end;
    Init := res;
end;

function Add(a, b : BigInteger) : BigInteger;
var sum, i : integer;
    res : BigInteger;
begin
    while (i < a.size) or (i < b.size) or (sum > 0) do
    begin
        sum := sum + a.digits[i] + b.digits[i];
        res.digits[i] := sum mod 10;
        sum := sum div 10;
        res.size := res.size + 1;
        i := i + 1;
    end;
    Add := res;
end;

procedure Print(var f : text; a : BigInteger);
var i : integer;
begin
    for i := a.size - 1 downto 0 do
    begin
        write(fout, a.digits[i]);
    end;
    if (a.size = 0) then
    begin
      write(fout, 0);
    end;
    writeln(fout, '');
end;

function Solve(n, k : integer) : BigInteger;
var dp : array [1..444, 1..444, 0..1] of BigInteger;
    i, j, x, sum1, sum0 : integer;
    res_sum : BigInteger;
begin
  if (k = 1) and (n = 1) then
  begin
    res_sum := Init('1');
  end;
  
  for i := 1 to n do //длина 1
  begin
    dp[1][i][1] := Init('1');
    if (i <> 1) then dp[1][i][0] := Init('1');
  end;
  
  for i := 2 to k do
  begin
    for j := 1 to n do
    begin
      for x := 1 to j - 2 do
      begin
        dp[i][j][1] := Add(dp[i][j][1], dp[i - 1][x][1]); //сумма всех подмножеств, заканчивающихся на i элемент
        dp[i][j][0] := Add(dp[i][j][0], dp[i - 1][x][0]); //сумма подмножеств, в которых нет цифры 1 и которые заканчиваются на i элемент
      end;
    end;
  end;
  
  for i := 1 to n - 1 do
  begin
    res_sum := Add(res_sum, dp[k][i][1]);
  end;
  res_sum := Add(res_sum, dp[k][n][0]);
  Solve := res_sum;
end;



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
    Print(fout, Solve(n, k));
  end;
  close(fin);
  close(fout);  
end.
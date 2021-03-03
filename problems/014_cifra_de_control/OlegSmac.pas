function Pow10(n : integer) : integer;
var res, i : integer;
begin
  res := 1;
  for i := 0 to n - 1 do
  begin
    res := res * 10;
  end;
  Pow10 := res;
end;

function Finding_sum(num : integer) : integer;
var i, sum : integer;
begin
  while (num > 0) do
  begin
    i := num mod 10;
    sum := sum + i;
    num := num div 10;
  end;
  Finding_sum := sum;
end;

function Solve(num : integer) : integer;
begin
  while (num > 9) do
  begin
    num := Finding_sum(num);
  end;
  Solve := num;
end;

var fin, fout : text;
    n, k, M, i : integer;
begin
  assign(fin, 'CIFRA.IN');
  reset(fin);
  assign(fout, 'CIFRA.OUT');
  rewrite(fout);
  read(fin, n);
  read(fin, k);
  
  for i := Pow10(n - 1) to Pow10(n) - 1 do
  begin
    if (Solve(i) = k) then
    begin
      M := M + 1;
    end;
  end;
  writeln(fout, M);
  close(fin);
  close(fout);
end.
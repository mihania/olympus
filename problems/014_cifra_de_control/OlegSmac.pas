function Pow(n : integer) : integer;
var res, i : integer;
begin
  i := 0;
  res := 1;
  while i < n do
  begin
    res := res * 10;
    i := i + 1;
  end;
  Pow := res;
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
var i, sum : integer;
begin
  while (num > -1) do
  begin
    sum := Finding_sum(num);
    if (sum <= 9) then
    begin
      num := sum;
      break;
    end
    else begin
      num := sum;
    end;  
  end;
  Solve := num;
end;

var fin, fout : text;
    n, k, M, i, j, start, finish : integer;
begin
  assign(fin, 'CIFRA.IN');
  reset(fin);
  assign(fout, 'CIFRA.OUT');
  rewrite(fout);
  read(fin, n);
  read(fin, k);
  start := Pow(n - 1);
  finish := Pow(n);
  
  for i := start to finish - 1 do
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
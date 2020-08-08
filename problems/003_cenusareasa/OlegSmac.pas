var
  fin : text;
  fout : text;
  N,i : integer;
  len, maxl : real;
  x: array of integer;
  y: array of integer;
begin
  assign(fin,'C:\src\olympus\problems\003_cenusareasa\TEST1.IN');
  reset(fin);
  assign(fout,'C:\src\olympus\problems\003_cenusareasa\TEST1.OUT');
  rewrite(fout);
  read(fin, N);
  setLength(x, N);
  setLength(y, N);
  for i := 0 to N - 1 do
  begin
    read(fin, x[i]);
    read(fin, y[i]);
  end;
  for i := 1 to N-1 do
  begin
    len := sqrt(sqr(x[i] - x[i - 1]) + sqr(y[i] - y[i - 1]));
    if len > maxl then maxl := len;  
  end;
  writeln(x);
  writeln(y);
  writeln(maxl:0:4); 
  close(fin);
  close(fout);
end.
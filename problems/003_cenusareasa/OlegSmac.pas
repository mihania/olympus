var
  fin : text;
  fout : text;
  N,i,j : integer;
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
  for i := 0 to length(x)-1 do
  begin
    for j := i+1 to length(y)-1 do
    begin
      len := sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j])); 
      if len > maxl then maxl := len;   
    end; 
  end;
  writeln(fout, maxl:0:4); 
  writeln(maxl:0:4); 
  close(fin);
  close(fout);
end.


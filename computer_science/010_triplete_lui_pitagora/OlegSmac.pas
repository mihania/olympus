function NOD(a, b : integer) : integer;
begin
  while (a <> b) do 
  begin
    if (a > b) then
    begin
      a := a - b;
    end;
    if (b > a) then
    begin
      b := b - a;
    end;  
  end;
  NOD := a;
end;

var 
  fin, fout : text;
  a, b, c, n : int64;
begin
  assign(fin, 'TRIPLETE.IN');
  reset(fin);
  assign(fout, 'TRIPLETE.OUT');
  rewrite(fout);
  read(fin, c);
  for a := 1 to c - 1 do
  begin
    b := round(sqrt(sqr(c) - sqr(a)));
    if (sqr(a) + sqr(b) = sqr(c)) and (a < b) then
    begin
      if NOD(a, b) = 1 then
      begin
        writeln(fout, a, ' ', b, ' ', c);
        n := n + 1;  
      end;
    end;
  end;
  if (n = 0) then
  begin
    writeln(fout, 'NOPE');
  end;
  close(fin);
  close(fout);
end.

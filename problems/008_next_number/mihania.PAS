program NextNumber;
var
  fin, fout : text;
  i, a, n : longint;
begin
  assign(fin, 'NUMBERS.IN');
  reset(fin);
  assign(fout, 'NUMBERS.OUT');
  rewrite(fout);
  readln(fin, n);
  for i := 1 to n do
  begin
    readln(fin, a);
    writeln(fout, a + 1);
  end;
  close(fin);
  close(fout);
end.


var
  ftext : text;
  rtext : text;
  i,x,y : integer;
begin
  assign(ftext,'NUMBERS.IN');
  reset(ftext);
  assign(rtext,'NUMBERS.OUT');
  rewrite(rtext);
  readln(ftext, y);
  for i := 1 to y do
   begin
      readln(ftext, x);
      x:= x + 1;
      writeln(rtext, x);
      writeln(x);
   end;
  close(ftext);
  close(rtext);
end.

program Olymp;
var
  fin, fout: text; 
  n, a, i: longint;
begin
  assign(fin,'Numberin.txt');
  reset(fin);
  assign(fout,'numberout');
  rewrite(fout);
  readln(fin, n);
  for i:= 1 to n do
  begin
    readln(fin, a);
    while(a > 9) do
    begin
      a := a mod 10 + a div 10;
       if (a = 7) then
      begin
        writeln(fout, 'norocos');
      end;
      if (a = 8) then
      begin
        writeln(fout, 'vorbaret');
      end;
      if(a = 9) then
      begin
        writeln(fout, 'intelegent');
      end;
      if(a <= 6) then
      begin
        writeln(fout, 'obisnuit');
      end;
    end;
  end;
  close(fin);
  close(fout);
end.
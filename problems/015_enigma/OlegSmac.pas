var fin, fout : text;
    s1, s2 : string;
    i, j, start, finish, L, G : integer;
begin
  assign(fin, 'ENIGMA.IN');
  reset(fin);
  assign(fout, 'ENIGMA.OUT');
  rewrite(fout);  
  readln(fin, s1);
  readln(fin, s2);
  writeln('s1 = ', s1);
  writeln('s2 = ', s2);
  start := 1;
  if (length(s1) <= length(s2)) then 
  begin
    finish := length(s1);
  end;
  
  while (finish <= length(s2)) do
  begin
    writeln('start = ', start);
    writeln('finish = ', finish);
    L := 0;
    j := 1;
    
    for i := start to finish do
    begin
      if (s2[i] = s1[j]) then
      begin
        L := L + 1;
      end;
      j := j + 1;
    end;
    writeln('L = ', L);
    G := G + L;
    start := start + 1;
    finish := finish + 1;
  end;
  writeln(fout, , G);
end.
var fin, fout : text;
    s1, s2 : string;
    i, j, x, start, finish, L, G : integer;
begin
  assign(fin, 'ENIGMA.IN');
  reset(fin);
  assign(fout, 'ENIGMA.OUT');
  rewrite(fout);  
  readln(fin, s1);
  readln(fin, s2);
  start := 1;
  
  for finish := length(s1) to length(s2) do
  begin
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
    G := G + L;
    start := start + 1;
  end;
  writeln(fout, G);
  close(fin);
  close(fout);
end.
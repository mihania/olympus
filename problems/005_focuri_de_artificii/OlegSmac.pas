var
  fin : text;
  fout : text;
  i, j, n, res : integer;
  h: array of integer;
  a: array of integer;
  b: array of integer;
  l: array of integer;
begin
  assign(fin,'C:\src\olympus\problems\005_focuri_de_artificii\TEST1.IN');
  reset(fin);
  assign(fout,'C:\src\olympus\problems\005_focuri_de_artificii\TEST1.OUT');
  rewrite(fout);
  read(fin, N);
  setLength(h, N);
  setLength(a, N);
  setLength(b, N);
  setLength(l, N * 3);
  for i := 0 to N - 1 do
  begin
    read(fin, h[i]);
    read(fin, a[i]);
    read(fin, b[i]);
  end;
  for i := 0 to length(l)-1 do 
  begin
    l[i] := l[i] + 1;
  end;
  for i := N-1 downto 0 do //каждый новый i - это новый блок
  begin
    for j := N-1 downto i+1 do  
    begin
      if (a[i] <= h[j]) and (h[j] <= b[i]) and (l[j] + 1 > l[i]) then
      begin
        l[i] := l[j] + 1;
        res := Max(res, l[i]);    
      end;
      if i+1 = j then
      begin
      write('l[i] = ', l[i]);
      write(' i = ', i);
      writeln(' j = ', j);
      end;
    end;
  end;
  writeln(fout, res); 
  writeln(res); 
  close(fin);
  close(fout);
end.
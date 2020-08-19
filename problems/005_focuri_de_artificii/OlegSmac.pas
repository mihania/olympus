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
  setLength(l, N);
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
  for j := N-1 downto 0 do //каждый новый i - это новый блок
  begin
    for i := N-1 downto j+1 do  
    begin
      if (a[j] <= h[i]) and (h[i] <= b[j]) then
      begin
        l[j] := Max(l[j], l[i] + 1);
        res := Max(res, l[j]); 
      end;
    end;
  end;
  writeln(fout, res);  
  close(fin);
  close(fout);
end.
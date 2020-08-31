var
  fin : text;
  fout : text;
  p, q, N, i, tmp : integer;
begin
  assign(fin,'BACTERII.IN');
  reset(fin);
  assign(fout,'BACTERII.OUT');
  rewrite(fout);
  read(fin, p);
  read(fin, q);
  read(fin, N);
  for i := 0 to N-1 do
  begin
    tmp := p + q;
    q := p;
    p := tmp;
  end;
  write(fout, p + q);
  close(fin);
  close(fout);
end.  
var
  fin : text;
  fout : text;
  i, j, n, res : integer;
  h: array of integer;
  a: array of integer;
  b: array of integer;
  f: array of integer;
  dp: array of integer;
begin
  assign(fin,'TESTS.IN');
  reset(fin);
  assign(fout,'TESTS.OUT');
  rewrite(fout);
  read(fin, N);
  setLength(h, N);
  setLength(a, N);
  setLength(b, N);
  setLength(f, N);
  setLength(dp, N);
  for i := 0 to N - 1 do
  begin
    read(fin, h[i]);
    read(fin, a[i]);
    read(fin, b[i]);
    read(fin, f[i]);
  end;
  for i := 0 to N-1 do
  begin
    dp[i] := f[i];
    for j := 0 to i-1 do 
    begin
      if (a[j] <= h[i]) and (h[i] <= b[j]) then
      begin
         dp[i] := Max(dp[i], f[i] + dp[j]);
      end;
    end;
    res := Max(res, dp[i]);
  end;
  write(fout, res);
  close(fin);
  close(fout);
end.
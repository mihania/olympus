var
  fin : text;
  fout : text;
  i, j, n, res : integer;
  h: array of integer;
  a: array of integer;
  b: array of integer;
  dp: array of integer;
begin
  assign(fin,'TEST1.IN');
  reset(fin);
  assign(fout,'TEST1.OUT');
  rewrite(fout);
  read(fin, N);
  setLength(h, N);
  setLength(a, N);
  setLength(b, N);
  setLength(dp, N);
  for i := 0 to N - 1 do
  begin
    read(fin, h[i]);
    read(fin, a[i]);
    read(fin, b[i]);
  end;
  for i := 0 to N-1 do //каждый новый i - это новый блок
  begin
    dp[i] := 1;
    for j := 0 to i-1 do  
    begin
      if (a[j] <= h[i]) and (h[i] <= b[j]) then
      begin
        dp[i] := Max(dp[i], dp[j] + 1); 
      end;
    end;
    res := Max(res, dp[i]);
  end;
  writeln(fout, res);
  close(fin);
  close(fout);
end.
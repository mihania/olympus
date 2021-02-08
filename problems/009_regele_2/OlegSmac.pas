var fin, fout : text;
    N, S, i, j, tmp, max_idx : longint;
    A : array [0..255] of longint;
    dp : array [0..255] of longint;
    idx : array [0..255] of longint;
    pred : array [0..255] of longint;
    cities : array [0..255] of longint;
begin
  assign(fin, 'REGE.IN');
  reset(fin);
  assign(fout, 'REGE.OUT');
  rewrite(fout);
  read(fin, N);
  readln(fin, S);
  max_idx := -1;
  for i := 0 to N - 1 do
  begin
    readln(fin, A[i]);
  end;

  for i := 1 to N - 1 do
  begin
    for j := 0 to i - 1 do
    begin
      if A[i] < A[j] then
      begin
        tmp := A[i];
        A[i] := A[j];
        A[j] := tmp;
      end;
    end;
  end;

  for i := High(A) - 1 downto 0 do
  begin
    if (A[i] < S) then
    begin
      dp[i] := A[i];
      idx[i] := i;
      pred[i] := A[i];
      cities[i] := 1;
      for j := i + 1 to High(A) - 1 do
      begin
        if (A[i] <= S - dp[j]) and
           (A[i] < pred[j]) and
           (dp[i] < dp[j] + A[i]) then
        begin
          dp[i] := dp[j] + A[i];
          idx[i] := j;
          pred[i] := pred[j] - A[i];
          cities[i] := cities[j] + 1;
        end;
      end;
      if (max_idx = -1) or (dp[i] > dp[max_idx]) then
      begin
        max_idx := i;
      end;
    end;
  end;

  if (max_idx = -1) then
  begin
    write(fout, S, ' ');
  end
  else begin
    write(fout, cities[max_idx], ' ');
    writeln(fout, S - dp[max_idx]);
    while (max_idx <> idx[max_idx]) do
    begin
      {write('max_idx = ', max_idx, ' idx[max] = ', idx[max_idx]);}
      writeln(fout,  A[max_idx]);
      max_idx := idx[max_idx];
    end;
  end;
  writeln(fout, A[max_idx]);
  readln;

  close(fin);
  close(fout);
end.
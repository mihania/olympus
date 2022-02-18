program casa_moderna_2;
var
  fin, fout : text;
  N, i, j, p, res, zero : integer;
  time : array of integer;
begin
  assign(fin, 'cas.in');
  reset(fin);
  assign(fout, 'cas.out');
  rewrite(fout);
  read(fin, N);
  setLength(time, N);
  for i := 0 to N - 1 do
  begin
    read(fin, time[i]);
  end;
  
  for i := 1 to length(time) - 1 do // сортировка массива
  begin
    for j := 0 to i do begin
      if (time[i] < time[j]) then
      begin
        p := time[i];
        time[i] := time[j];
        time[j] := p;
      end;
    end;
  end;
  
  i := 0;
  for j := 0 to length(time) - 1 do
  begin
    if (time[j] = 0) then
    begin
      zero := zero + 1;
    end;
    if (time[j] <> 0) and (i + 1 <= time[j]) then
    begin
      i := i + 1;
    end;
  end;
  writeln('i = ', i);
  writeln('zero = ', zero);
  i := i + zero;
  
  if (i = length(time)) then
  begin
    res := 1;
  end
  else
  begin
    res := 0;
  end;
  write(fout, res);
  write(res);
  close(fin);
  close(fout);
end.

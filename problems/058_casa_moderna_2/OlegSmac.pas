program casa_moderna_2;
var
  fin, fout : text;
  N, i, j, p, res : integer;
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
        time[j] := p
      end;
    end;
  end;
  
  i := 0;
  while (i < length(time) - 1) and (i + 1 <= time[i]) do //расчеты
  begin
    i := i + 1;
  end;
<<<<<<< HEAD
  if (i = length(time) - 1) then
  begin
    res := 1;
  end
  else
  begin
    res := 0;
  end;
  write(fout, res);
  write(res);
=======
  write(fout, res);
>>>>>>> df372877d8b1b65b411deaa28b29a90c4ad2e569
  close(fin);
  close(fout);
end.

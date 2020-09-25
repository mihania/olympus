program NumerSum;
var
  fin, fout : text;
  N, i, j, num, first, sum2, d : integer;
  nums : array of integer;
begin
  assign(fin, 'C:\PABCWork.NET\olimp\joc.in');
  reset(fin);
  assign(fout, 'C:\PABCWork.NET\olimp\joc.out');
  rewrite(fout);
  read(fin, N);
  setLength(nums, N);
  for i := 0 to N-1 do //проверка условия: первое число равно сумме отсальных чисел
  begin
    sum2 := 0;
    read(fin, num);
    nums[i] := num;
    while (num > 0) do
    begin
      sum2 := sum2 + num mod 10;
      num := num div 10;
      if (num <= 9) and (num <> 0) then first := num;
      //writeln('sum2 = ', sum2);
      //writeln('num = ', num);
      writeln();
    end;
    //writeln('first = ', first);
    sum2 := sum2 - first;
    if (first <> sum2) then nums[i] := 0;
    //writeln('nums[i] = ', nums[i]);
  end;

  for i := 1 to N - 1 do //сортировака массива по убыванию
  begin
    for j := 0 to i - 1 do
    begin
      if nums[i] > nums[j] then
      begin
        d := nums[i];
        nums[i] := nums[j];
        nums[j] := d;
      end;
    end;
  end;
  for i := 0 to N - 1 do //вывод массива
  begin
    if (nums[i] <> 0) then
    begin
    writeln(nums[i]);
    write(fout, nums[i]);
    end;
  end;
  close(fin);
  close(fout);
end.
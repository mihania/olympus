program NumerSum;
var
  fin, fout : text;
  N, i, j, num, sum, tmp : integer;
  nums : array of integer;
begin
  assign(fin, 'joc.in');
  reset(fin);
  assign(fout, 'joc.out');
  rewrite(fout);
  read(fin, N);
  setLength(nums, N);
  for i := 0 to N - 1 do //проверка условия: первое число равно сумме отсальных чисел
  begin
    sum := 0;
    read(fin, num);
    nums[i] := num;
    while (num > 9) do
    begin
      sum := sum + num mod 10;
      num := num div 10;
    end;
    if (num <> sum) then nums[i] := 0;
  end;

  for i := 1 to N - 1 do //сортировака массива по убыванию
  begin
    for j := 0 to i - 1 do
    begin
      if nums[i] > nums[j] then
      begin
        tmp := nums[i];
        nums[i] := nums[j];
        nums[j] := tmp;
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
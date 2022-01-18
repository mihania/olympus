var fin, fout : text;
    N, i, j, min, min_ind, tmp, chet : integer;
    nums : array of integer;
begin
  assign(fin, 'SORTARE.IN');
  reset(fin);
  assign(fout, 'SORTARE.OUT');
  rewrite(fout);
  read(fin, N);
  setLength(nums, N);
  for i := 0 to N - 1 do 
  begin
    read(fin, nums[i]);
  end;
  
  for i := 0 to N - 1 do
  begin
    min := nums[i];
    for j := i + 1 to length(nums) - 1 do
    begin
      if (nums[j] < min) then
      begin
        min := nums[j];
        min_ind := j;
      end;
    end;
    
    if (min < nums[i]) then
    begin
      tmp := nums[min_ind];
      nums[min_ind] := nums[i];
      nums[i] := tmp;
      chet := chet + 1;
    end;
  end;
  write(fout, chet);
  close(fin);
  close(fout);
end.
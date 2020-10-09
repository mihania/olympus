Program Micul_prinz;
var
  fin, fout : text;
  N, i, num : integer;
  
  function isPalindrome(num : integer) : boolean;
  var 
    s : string;
    i, j : integer;
  begin
    Str(num, s);
    i := 1;
    j := Length(s);
    while (i < j) and (s[i] = s[j]) do
    begin
        j := j - 1;
        i := i + 1;
    end;
    isPalindrome := i >= j;
  end;
  
begin
  assign(fin, 'pal.in');
  reset(fin);
  assign(fout, 'pal.out');
  rewrite(fout);
  read(fin, N);
  for i := 0 to N - 1 do 
  begin
    read(fin, num);
    while (isPalindrome(num) <> true) do
    begin
      num := num + 1;
    end;
    writeln(fout, num);
    
  end;
  close(fin);
  close(fout);
end.
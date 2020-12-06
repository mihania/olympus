var
  fin : text;
  fout : text;
  N, i, p_int, q_int : integer;
  p, q, tmp : string;
  
  function add(s1, s2 : string) : string;
  var
    a, b, sum, err, l1, l2 : integer;
    res, sum_str : string;
  begin
    l1 := length(s1);
    l2 := length(s2);
    while (l1 > 0) or (l2 > 0) or (sum > 0) do
    begin
      a := 0;
      b := 0;
      if (l1 > 0) then
      begin
        val(s1[l1], a, err);
      end;
      if (l2 > 0) then
      begin
        val(s2[l2], b, err);
      end;
      l1 := l1 - 1;
      l2 := l2 - 1;
      
      sum := sum + a + b;
      str(sum mod 10, sum_str);
      sum := sum div 10;
      res := sum_str + res;
    end;
    add := res;
  end;
begin
  assign(fin,'BACTERII.IN');
  reset(fin);
  assign(fout,'BACTERII.OUT');
  rewrite(fout);
  read(fin, p_int);
  read(fin, q_int);
  read(fin, N);
  str(p_int, p);
  str(q_int, q);
  for i := 0 to N - 1 do
  begin
    tmp := add(p, q);
    q := p;
    p := tmp;
  end;
  write(fout, add(p, q));
  close(fin);
  close(fout);
end. 
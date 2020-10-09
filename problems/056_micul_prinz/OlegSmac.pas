Program Micul_prinz;
var
  fin, fout : text;
  N, i, num, q, len, j : integer;
  v : boolean;
  palin : array of integer;
  function f(n2 : integer) : boolean;
  var i : integer;
  begin
    n2 := num;
    while (n2 > 0) do
    begin
      q := n2 mod 10;
      n2 := n2 div 10;
      len := len + 1;
    end;
    setLength(palin, len);
    n2 := num;
    while (n2 > 0) do
    begin
      len := len - 1;
      q := n2 mod 10;
      palin[len] := q;
      n2 := n2 div 10;
    end;
    j := length(palin) - 1;
    for i := 0 to j do
    begin
      if palin[i] = palin[j] then 
      begin
      j := j - 1; 
      v := true;
      end
      else 
      begin
      v := false; 
      break;
      end;
    end;
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
    while (v <> true) do
    begin
      (f(num));
      num := num + 1;
    end;
    v := false;
    writeln(fout, num - 1);
    writeln('num = ', num - 1);
  end;
end.
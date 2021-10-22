program regiuni2;
type 
  UnionFind = class
  private n : integer;
  private id : array of integer;
  private sz : array of integer;
  private count : integer;
  
  public constructor Create(num : integer);
  var i : integer;
  begin
    n := num;
    count := num;
    setLength(id, n);
    setLength(sz, n);
    for i := 0 to n - 1 do
    begin
      id[i] := i;
      sz[i] := 1;
    end;
  end;
  
  function getCount : integer;
  begin
    Result := count;
  end;
  
  function find(i : integer) : integer;
  begin
    while (i <> id[i]) do
    begin
      i := id[i];
    end;
    Result := i;
  end;
  
  procedure union(p, q : integer);
  var i, j : integer;
  begin
    i := find(p);
    j := find(q);
    {writeln('i = ', i, ' j = ', j);}
    if (i = j) then
    begin
      exit;
    end;
    if (sz[i] < sz[j]) then
    begin
      id[i] := j;
      sz[j] := sz[j] + sz[i];
    end
    else 
    begin
      id[j] := i;
      sz[i] := sz[i] + sz[j];
    end;
    count := count - 1;
  end;
end;

var fin, fout : text;
    i, n, p, q : integer;
    reg : UnionFind;
begin
  assign(fin, 'reg.in');
  reset(fin);
  assign(fout, 'reg.out');
  rewrite(fout);
  read(fin, n);
  reg := new UnionFind(n);
  for i := 0 to n - 1 do
  begin
    read(fin, p);
    read(fin, q);
    if (p = 0) or (q = 0) then
    begin
      break;
    end;
    reg.union(p - 1, q - 1);
  end;
  writeln('smaller number of regiuni = ', reg.count);
end.
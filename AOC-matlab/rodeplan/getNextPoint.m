function nextpointindex = getNextPoint(p)
% 使用轮盘赌法给出下一个点
% p                 input  概率列表
% nextpointindex    output 下一个点
sump = sum(p);
p = p / sump;
cumsump = cumsum(p);
list = find(cumsump >= rand);
nextpointindex = list(1);
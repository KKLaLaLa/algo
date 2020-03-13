function rpop = decodechrom(pop, spoint, length)
% 将每行中列为spoint : spoint+length-1的二进制矩阵转化为十进制数
% pop       input  种群
% spoint    input  开始位置
% length    input  长度
% rpop      output 十进制列向量
tpop = pop(:, spoint: spoint+length-1);
rpop = decodebinary(tpop);
end
function [objvalue] = calobjvalue(pop, lx, ux)
% 计算目标函数值，需根据实际情况重写
% pop       input  种群
% lx        input  自变量最小值
% ux        input  自变量最大值
% objvalue  output 目标函数值
decchrom = decodechrom(pop, 1, size(pop, 2));  % 将二进制转化为十进制
x = decchrom / (2^size(pop ,2)-1) * (ux - lx) + lx;
objvalue = 9 * sin(5 * x) + 8 * cos(4 * x);
end
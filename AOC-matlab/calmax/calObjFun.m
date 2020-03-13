function objval = calObjFun(X)
% 计算目标函数值
% X         input  点输入 [x, y] nx2
% objvalue  output 输出 nx1
objval = -(X(:,1) .^ 4 + 3 .* X(:,2) .^ 4 - 0.2 .* cos(3*pi .* X(:,1)) ...
    - 0.4 .* cos(4*pi .* X(:,2)) + 0.6);

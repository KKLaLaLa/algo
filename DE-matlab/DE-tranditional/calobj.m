function z = calobj (pop)
% 计算目标函数值
% pop       input  种群
% z         output 目标函数值
z = 3 * cos(pop(:,1) .* pop(:,2)) + pop(:,1) + pop(:,2);
end
function D = distancematrix(pos)

N = size(pos,2);
D = zeros(N,N);

for i = 1:N
    for j = i+1:N
        dis = (pos(1,i) - pos(1,j)).^2 + (pos(2,i) - pos(2,j)).^2;
        D(i,j) = dis^(0.5);
        D(j,i) = D(i,j);
    end
end
end

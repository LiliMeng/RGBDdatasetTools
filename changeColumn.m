fid1 = fopen('associatedDataFinal.txt');
C = textscan(fid1, '%s %s %s %s');


N = size(C{1}, 1);
index = [1:N];


M=cell2mat(C{1});
M1=cell2mat(C{2});
M2=cell2mat(C{4});



fid2 = fopen('outputAssociatedData.txt', 'w');
for i = [1:N]
    fprintf(fid2, '%d %s %s\n', index(i), M1(i,:), M2(i,:));
end

fclose(fid1);
fclose(fid2);

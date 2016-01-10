fid1 = fopen('Fr1Desk2FovisPoseData.txt');
C = textscan(fid1, '%s %s %s %s');

timestamp=cellstr(C{1});
x=cellstr(C{2});
y=cellstr(C{3});
z=cellstr(C{4});


N=size(timestamp,1)


fid2 = fopen('fr1Desk2poseFinal.txt', 'w');

for i=[1:N]
    fprintf(fid2, '%s %s %s %s\n',C{1}{i},C{2}{i},C{3}{i},C{4}{i})
end

fclose(fid1);
fclose(fid2);

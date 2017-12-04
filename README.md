# Tugas Besar 2 Jaringan Komputer
## Anggota
Wenny Yustalim (13515002)
Daniel Pintara (13515071)
Helena Suzane Graciella (13515032)

## Petunjuk Penggunaan Program
Pada root directory, compile program dengan mengetik:
```
make
```

Untuk menjalankan program dengan testcase test.txt dalam folder data, ketik:
```
make test
```

Untuk menjalankan program dengan input manual, ketik:
```
make run
```

## Penjelasan Program
### Simulasi Node
Terdapat sebuah matriks bernama 'table' berukuran n_node * n_node di mana n_node adalah jumlah node pada jaringan. table[i] merepresentasikan hubungan antara node i dengan node lainnya. table[i][j] merepresentasikan adanya hubungan sebuah node i dengan node j (1 jika ada hubungan, 0 jika tidak).
Struktur data yang digunakan adalah tuple yang berisi distance dan next_hop. Tuple ini disimpan dalam matrix of connectivity (yang berisi n_node rows dan n_node columns).

### Proses Pengiriman Pesan Antarnode
Untuk setiap pengiriman pesan dari node a ke node b, akan dilihat routing table node a, apakah terdapat hubungan antara node a dengan node b. Jika iya, maka routing table node a tidak mengalami perubahan. Routing table node b akan melihat routing table node a. Jika ada node yang lain yang berhubungan dengan node a tetapi tidak berhubungan dengan node b, maka node b akan diupdate. Jarak dari node b ke node yang berhubungan dengan node a akan diisi jarak dari node tersebut ke node a ditambah dengan jarak dari node a ke node b, dan nexthop adalah node a. Tetapi, jika sudah terdapat hubungan antara node b dengan node-node yang berhubungan dengan node a, akan dilihat jarak minimum antara node b ke node tersebut, apakah melalui nexthop sebelumnya atau melalui node a. Jika distancenya sama, maka akan diambil nexthop dengan node terkecil. Jika tidak ada hubungan antara node a dan node b, tidak akan terjadi apa-apa.

## Pembagian tugas
1. 13515002: mengerjakan bagian routing table
2. 13515032: mengerjakan readme dan testing
3. 13515071: mengerjakan bagian input

## Pertanyaan-Jawaban
### Perbedaan routing protocol distance-vector dan link state; yang mana yang lebih baik untuk digunakan
Pada distance vector, setiap node memiliki tabel jarak antara node tersebut dengan setiap node lainnya. Node-node tersebut kemudian saling bertukar tabel, dan jika ditemukan jalur yang lebih cepat, tabel akan diupdate. Di awal, sebuah node hanya mengetahui jarak ke tetangga yang berhubungan langsung. Jarak ke node lain diinisialisasi dengan infinity atau -1 (atau sebagainya).
Sedangkan pada link state, setiap node mengetahui cost ke tetangga terdekat. Informasi link cost disebar ke seluruh node, dan masing-masing node dapat menghitung shortest path ke setiap node lain. Masing-masing node mengirimkan informasi ke seluruh link yang dimilikinya. Saat menerima informasi, sebuah node akan mem-forward informasi tersebut ke seluruh link lainnya.
Dalam mengirim pesan, distance vector akan menggunakan rute dengan hops paling sedikit. Sedangkan link state mempertimbangkan juga hal-hal lainnya, misalnya bandwidth pada sebuah link.
Jika medium antar-node memiliki kecepatan (atau faktor biaya lainnya) yang berbeda-beda, link state dapat lebih baik daripada distance vector, karena ia menyimpan cost untuk mengirim pada node-node lainnya. Sedangkan distance vector dapat berkinerja lebih baik jika setiap link pada network memiliki kecepatan yang sama.
### Implementasi distance-vector dan link state pada saat ini: yang mana yang lebih sering dipakai dan mengapa
Pada awalnya, distance vector protocol jauh lebih mudah untuk didesain dan diimplementasikan pada software, jadi distance vector protocol lebih popouler. Tetapi, karena pada saat itu belum ada invention baru, distance vector protocol memiliki beberapa drawback terutama dari kecepatannya dalam reaksi terhadap perubahan di network dan bagaimana protocol ini menghindari membuat sebuah routing loop. Sementara, pendekatan lain pada routing protocol design, yaitu pendekatan link state, dikembangkan. Link state protocol jauh lebih kompleks dan membutuhkan lebih banyak processing power dan memori, tetapi seiring dengan membaiknya resource pada router, link state routing protocol pelan-pelan menggantikan distance vector protocol.

#Acknowledgement
Terimakasih pada dosen pengampu matakuliah IF3140 Jaringan Komputer

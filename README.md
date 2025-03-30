# <center>Fikstür Oluşturma Ödevi</center>

Kullanıcının sınırlar belirleyip kendi konumunu ve istediği kadar başka konumlar girerek kendisine olan uzaklıkları ve en yakın ve uzak olan konumları gösteren kod.

## Proje Gereksinimleri

### Kod derleme araçları

```
gcc
```

## Desteklenen İşletim Sistemleri

- Windows
- Linux

## El ile Koşturma

### Windows

```
./labirent.exe
```

### Linux

```
./labirent.o
```

## El ile Derleme

### Gereksinimleri İndirme

#### Fedora

```
sudo dnf install gcc
```

#### Ubuntu

```
sudo apt-get install gcc
```

#### Windows

```
Mingw64-gcc
```

### Kodu Derleme

#### Windows
```
gcc -o labirent.exe labirent.c
```

#### Windows
```
gcc -o labirent.o labirent.c
```


## Dikkat Edilmesi Gerekenler

- Kod sadece integer değerler alır. Başka tür bir değişken girmeniz kodu çalıştırmayabilir hatta hatalı çalıştırabilir.
- Manhattan yöntemiyle mesafe hesaplanmıştır.  Yani mesafeler öklide göre fazla çıkabilir. Manhattan yöntemi (|x<sub>1</sub> - x<sub>2</sub>| + |y<sub>1</sub> - y<sub>2</sub>|)
- Eğer en yakın veya en uzak 1 den fazla yer varsa sadece 1 tanesini gösterir.

ToDoAppでは入力したタスクが再度起動後には消えていましたが、
再度起動してもファイルからの読み込み、出力により、
消えることなく起動しても前回のタスクが残ります。

また一つのファイルで構成されていたものを複数のファイルからの読み込みをし、
各メソッドごとに分かれて視野性などがよくなりました。

このアプリで勉強となったことは

・構造体配列、また構造体の配列化
・ポインタの操作（メソッドでのポインタ操作、配列された構造体へのアクセス）
・ファイルの読み込みと書き込み
・ファイル間でのやり取り（ヘッダファイルの活用）
・#defineの活用
などです。

流れや概要に関しては、gaiyou.txtに記載されています。
作成はVisual Stadioで作成しているため、一部依存した記載があります。（C++コンパイラによるエラー喚起を無効化する）

ToDoApp.cから始まります。
各ファイルの名称は各メソッドの頭文字を大文字にしたものとなっているため、
メソッド内容を調べる際はそれをもとに探すと探せるかと思います。

.hで終わるファイルはヘッダファイルです。
各ファイルに紐づけする役割になっています。

主な宣言などの記述はCreate.hに記載されており、それを各ヘッダファイルが読み込んでいます。
そしてそれらのヘッダファイルを各メソッドのファイルが参照しています。

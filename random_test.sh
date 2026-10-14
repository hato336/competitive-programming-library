#!/bin/zsh

# https://github.com/hato336/competitive-programming-library

# 使い方: ./test.sh <correct> <wrong> <generator>
# $1: 正解コード（.cpp を除く）
# $2: 検証するコード（.cpp を除く）
# $3: テストケース生成コード（.cpp を除く）
# 例: ./test.sh naive main gen

if [ $# -ne 3 ]; then
    echo "Usage: $0 <correct> <wrong> <generator>"
    exit 1
fi

source ~/.zshrc

# コンパイル
cmpl "$1.cpp" -o "$1" || exit 1
cmpl "$2.cpp" -o "$2" || exit 1
cmpl "$3.cpp" -o "$3" || exit 1

# 一時ファイルの準備
tmpdir=$(mktemp -d) || exit 1
trap 'rm -rf -- "$tmpdir"' EXIT

cnt=0
while true; do
    ((cnt++))

    # テストケース生成
    ./"$3" > "$tmpdir/input" 2> "$tmpdir/gen_err"
    gen_status=$?

    # 正解コードの実行
    if [ $gen_status -eq 0 ]; then
        ./"$1" < "$tmpdir/input" > "$tmpdir/correct" 2> "$tmpdir/correct_err"
        correct_status=$?

        # 検証コードの実行
        ./"$2" < "$tmpdir/input" > "$tmpdir/wrong" 2> "$tmpdir/wrong_err"
        wrong_status=$?
    fi

    # 結果判定
    if [ $gen_status -ne 0 ]; then
        echo "RE (generator) #$cnt (exit: $gen_status)"
        cat "$tmpdir/gen_err"
    elif [ $correct_status -ne 0 ]; then
        echo "RE (correct) #$cnt (exit: $correct_status)"
        cat "$tmpdir/correct_err"
    elif [ $wrong_status -ne 0 ]; then
        echo "RE (wrong) #$cnt (exit: $wrong_status)"
        cat "$tmpdir/wrong_err"
    elif ! cmp -s "$tmpdir/correct" "$tmpdir/wrong"; then
        echo "WA #$cnt"
    else
        echo "PASS #$cnt"
        continue
    fi

    # 失敗時の入力を保存
    cp "$tmpdir/input" wrong.txt

    echo
    echo "input:"
    cat "$tmpdir/input"
    echo
    echo "correct:"
    cat "$tmpdir/correct" 2>/dev/null
    echo
    echo "wrong:"
    cat "$tmpdir/wrong" 2>/dev/null
    echo
    echo "Saved to wrong.txt"
    exit 1
done
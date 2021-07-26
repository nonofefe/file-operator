convert_general: input/poke_general -> generate/poke_general
テーブルからポケモンの一般種族値を求める

get_kind100: input/poke_kind100 -> generate/poke_kind100
ファクトリーテーブルからレベル100のポケモンを抜き出す

get_kind501: input/poke_kind501 -> generate/poke_kind501
ファクトリーテーブルから1週目のポケモンを抜き出す

get_kind502: input/poke_kind502 -> generate/poke_kind502
ファクトリーテーブルから2週目のポケモンを抜き出す

make_sqlite3: generate/poke_general -> sqlite3/poke_general
sqlite3データベース作成のためのスクリプトを作成
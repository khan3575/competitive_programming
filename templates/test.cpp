//linux


{
    "shell_cmd": "g++ -std=c++17 -Wall -Wextra -O2 \"$file\" -o \"$file_path/$file_base_name\" && timeout 4s \"$file_path/$file_base_name\" < /eon/inputf.in | tee /eon/outputf.in",
    "file_regex": "^(..[^:]*):([0-9]+):?([0-9]*)",
    "working_dir": "$file_path",
    "selector": "source.c, source.c++",

    "variants": [
        {
            "name": "Debug (Safe Mode)",
            "shell_cmd": "g++ -std=c++17 -D_GLIBCXX_DEBUG -fsanitize=address,undefined -Wall -Wextra -g \"$file\" -o \"$file_path/$file_base_name\" && timeout 4s \"$file_path/$file_base_name\" < /eon/inputf.in | tee /eon/outputf.in"
        }
    ]
}


//mac

{
    "shell_cmd": "g++-14 -std=c++17 -Wall -Wextra -O2 \"$file\" -o \"$file_path/$file_base_name\" && gtimeout 4s \"$file_path/$file_base_name\" < /eon/inputf.in | tee /eon/outputf.in",
    "file_regex": "^(..[^:]*):([0-9]+):?([0-9]*)",
    "working_dir": "$file_path",
    "selector": "source.c, source.c++",

    "variants": [
        {
            "name": "Debug (Safe Mode)",
            "shell_cmd": "g++-14 -std=c++17 -D_GLIBCXX_DEBUG -fsanitize=address,undefined -Wall -Wextra -g \"$file\" -o \"$file_path/$file_base_name\" && gtimeout 4s \"$file_path/$file_base_name\" < /eon/inputf.in | tee /eon/outputf.in"
        }
    ]
}

//windows

{
    "shell_cmd": "g++ -std=c++17 -Wall -Wextra -O2 \"$file\" -o \"$file_path/$file_base_name\" && \"$file_path/$file_base_name\" < \"C:/eon/inputf.in\" > \"C:/eon/outputf.in\" && type \"C:\\eon\\outputf.in\"",
    "file_regex": "^(..[^:]*):([0-9]+):?([0-9]*)",
    "working_dir": "$file_path",
    "selector": "source.c, source.c++",

    "variants": [
        {
            "name": "Debug (Safe Mode)",
            "shell_cmd": "g++ -std=c++17 -D_GLIBCXX_DEBUG -fsanitize=address,undefined -Wall -Wextra -g \"$file\" -o \"$file_path/$file_base_name\" && \"$file_path/$file_base_name\" < \"C:/eon/inputf.in\" > \"C:/eon/outputf.in\" && type \"C:\\eon\\outputf.in\""
        }
    ]
}
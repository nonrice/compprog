with open("basedWatermelon.cpp", "w") as f:
    f.write("#include <iostream>\n\nint main(){\n")
    f.write("    int w;\n    std::cin >> w;\n")
    f.write("    std::cout << ((")
    for w in range(1,101):
        if w%2==0 and w>2:
            f.write("w==" + str(w) + "||")
    f.write("1203==120349) ? \"YES\" : \"NO\");\n}\n")




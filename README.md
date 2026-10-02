# parallel

Учебные проекты по C++ и параллелизму (OpenMP, std::thread, TBB, MPI).

    task new -- lab1      # копия template/ в lab1/
    cd lab1 && task run   # сборка и запуск
    task --list           # все команды

Переменные: `CXX=clang++`, `TYPE=Debug`, `THREADS=4`, `SAN=thread|address|undefined`.
`task docker:shell` — окружение в контейнере. Корневой Taskfile не нужен в самих подпроектах.

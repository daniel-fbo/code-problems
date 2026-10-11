#!/usr/bin/env python3
"""Gerador de testes aleatórios para o `stress`.
Recebe a semente como argumento e imprime UM caso de teste.
Dica: casos PEQUENOS acham bugs mais rápido e são fáceis de ler.
"""
import random
import sys

random.seed(int(sys.argv[1]) if len(sys.argv) > 1 else 0)

t = 1
print(t)
for _ in range(t):
    n = random.randint(1, 8)
    a = [random.randint(1, 10) for _ in range(n)]
    print(n)
    print(*a)

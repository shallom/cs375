#!/bin/bash
make lexer
lexer <scantst.pas > lexscan.txt
lexer <graph1.pas > lexgraph.txt
diff lexscan.txt lexsolscan.txt > lexscandiffs.txt
diff lexgraph.txt lexsolgraph.txt > lexgraphdiffs.txt 
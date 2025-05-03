# Cadastro de Alunos

Projeto em linguagem C para gerenciamento de cadastro de alunos via terminal.

## 📋 Funcionalidades

- Cadastrar aluno: Adiciona um novo aluno com nome, matrícula e curso.

- Cadastrar notas: Permite inserir as notas de cada aluno.

- Exibir o aluno com a maior média: Calcula e mostra o aluno que possui a maior média entre todos.

- Ordenar a lista de alunos pela média: Organiza a lista de alunos de forma decrescente, do aluno com maior média para o menor.

- Esvaziar a lista: Remove todos os alunos cadastrados, limpando a lista.

## 🛠️ Tecnologias Utilizadas

- Linguagem C
- Compilador GCC

## ✅ Pré-requisitos

Antes de rodar o projeto, certifique-se de ter:

- [GCC (GNU Compiler Collection)](https://gcc.gnu.org/) instalado
- Um terminal (Linux, macOS ou Windows com WSL, Git Bash ou similar)

## 🚀 Como Executar o Projeto

1. **Clone o repositório:**

   ```bash
   git clone https://github.com/Andrius-Anselmi/CadastroDeAlunos2.0.git
   ```

2. **Acesse o diretório do projeto:**

   ```bash
   cd CadastroDeAlunos2.0
   ```

3. **Compile o código:**

   ```bash
   gcc -o cadastro main.c
   ```

4. **Execute o programa:**

   ```bash
   ./cadastro
   ```

## 📁 Estrutura do Projeto

```
CadastroDeAlunos2.0/
├── main.c
├── aluno.h
├── aluno.c
└── README.md
```

## 🔮 Melhorias Futuras

- Armazenamento persistente em arquivo
- Sistema de menus mais interativo
- Interface gráfica (ex: com GTK ou ncurses)
- Validação de entrada de dados

## 📝 Licença

Este projeto está sob a licença MIT. Consulte o arquivo [LICENSE](LICENSE) para mais detalhes.

function selecionarBotao(root, botao) {
  if (root.botaoSelecionado)
    root.botaoSelecionado.selecionado = false

  root.botaoSelecionado = botao
  botao.selecionado = true
}

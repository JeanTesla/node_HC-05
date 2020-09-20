JeanTesla/node_HC-05

1 -> Faça a extração do arquivo e execute o comando "npm i" dentro da pasta para instalar as depedências.

2 -> Parear módulo com o notebook. Senha padrão do módulo: 1234 

3 -> No terminal: sudo rfcomm connect /dev/rfcomm 00:00:00:00:00:00 (endereço físico do módulo)

4 -> Iniciar script do servidor em outro terminal que conectará o socket e a portaSerial (index.js)

5 -> Esperar mensagem de sucesso se o socket e a portaSerial foram conectados.

6 -> Abrir html em algum browser (painel.html)

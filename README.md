JeanTesla/node_HC-05


1 -> Parear módulo com o notebook. Senha padrão do módulo: 1234 

2 -> No terminal: sudo rfcomm connect /dev/rfcomm 00:00:00:00:00:00 (endereço físico do módulo)

3 -> Iniciar script do servidor em outro terminal que conectará o socket e a portaSerial (index.js)

4 -> Esperar mensagem de sucesso se o socket e a portaSerial foram conectados.

5 -> Abrir html em algum browser (painel.html)

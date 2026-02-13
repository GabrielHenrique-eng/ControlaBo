from http.server import BaseHTTPRequestHandler, HTTPServer
from urllib.parse import urlparse, parse_qs

class Servidor(BaseHTTPRequestHandler):
    def do_GET(self):
        if self.path.startswith("/comando"):
            query = urlparse(self.path).query
            params = parse_qs(query)

            if "acao" in params:
                comando = params["acao"][0]
                print("Comando recebido:", comando)

                self.send_response(200)
                self.end_headers()
                self.wfile.write(b"OK")
            else:
                self.send_response(400)
                self.end_headers()
                self.wfile.write(b"Parametro ausente")
        else:
            self.send_response(404)
            self.end_headers()

server = HTTPServer(("0.0.0.0", 8080), Servidor)
print("Servidor rodando na porta 8080")
server.serve_forever()
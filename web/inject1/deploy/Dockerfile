FROM node:16

WORKDIR /usr/src/app

COPY ./source/package*.json ./
RUN npm install

COPY ./source/app.js ./
COPY ./source/views ./views

CMD [ "node", "app.js" ]

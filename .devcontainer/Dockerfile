FROM buildpack-deps:focal
RUN apt-get update && apt-get install -yqq libboost-context-dev libboost-dev wget libmariadb-dev\
            postgresql-server-dev-12 libpq-dev cmake python3-pip
RUN git clone https://github.com/matt-42/lithium.git /lithium
RUN mkdir /lithium/build;
RUN cd /lithium/build && cmake .. -DCMAKE_BUILD_TYPE=Release; make install -j4;
RUN apt-get install -yqq nodejs npm && alias cpm='npm'
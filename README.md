# python-tippecanoe

## Build

```sh
git clone https://github.com/mapbox/tippecanoe
cd tippecanoe
git clone https://github.com/mugwort-rc/python-tippecanoe python
cd python
python setup.py build
```

## Usage

```pycon
>>> import tippecanoe
>>> import tippecanoe as tip
>>> geom = tip.mvt_geometry(tip.mvt_moveto, 0, 0)
>>> feat = tip.mvt_feature()
>>> feat.geometry.append(geom)
>>> layer = tip.mvt_layer()
>>> layer.name = "example"
>>> layer.features.append(feat)
>>> tile = tip.mvt_tile()
>>> tile.layers.append(layer)
>>> pbf_data = tile.encode()
>>> pbf_data
'\x1a\x16x\x00\n\x07example(\x00\x12\x07\x18\x00"\x03\t\x00\x00'
```
